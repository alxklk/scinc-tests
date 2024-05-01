#!/usr/bin/python3

import sys
import subprocess
import glob
import re
import platform

compiler = 'g++'
# compiler='clang++'
# compiler='clang++.bat'
# compiler='cl.bat'


if platform.system() == "Windows":
    try:
        subprocess.call([compiler, 'ansi.c', '-s', '-o', 'ansi.exe'])
        subprocess.call(['ansi.exe'])
    except:
        print("Failed to enable ANSI\n")


def makeCompilerCommandline(src):
    if compiler == 'cl.bat':
        return [compiler, '/O2', src + '.cpp']
    else:
        return [compiler, '-O2', '-static', src + '.cpp', '-o', src + '.exe']


stdout = sys.stdout

sources = []
report = ''
listing = ''
err = ''
oks = 0
fails = 0
# scrip_exe='../cmake-build-debug/scrip'
# scrip_exe='../Scinc'
scrip_exe = 'Scinc'
# scrip_exe='../scrip'


if len(sys.argv) > 1:
    srclist = sys.argv[1:]
    for f in srclist:
        m = re.match(r'(.*?)\.cpp', f)
        if m:
            sources.append(m.group(1))
        else:
            sources.append(f)
    stdout.write('\nTesting ' + ','.join(srclist) + '\n')
else:
    cppfiles = glob.glob('*.cpp')
    for f in cppfiles:
        m = re.match(r'(.*?)\.cpp', f)
        if m:
            sources.append(m.group(1))

for src in sources:
    ok = True
    stdout.write("\033[0m")
    stdout.write('\n' + src + '\n')
    stdout.flush()
    listing += '// ********** ' + src + ' **********\n'
    comp = subprocess.Popen(
        makeCompilerCommandline(src), stdout=subprocess.PIPE, stderr=subprocess.PIPE, universal_newlines=True)
    comp.wait()

    stdout.write("G++ return code: " + str(comp.returncode) + "\n")

    if comp.returncode != 0:
        ok = False
        report += src + ' ' + compiler + '  failed to compile\n'
        continue

    for line in comp.stdout:
        stdout.write('g++:>' + line)

    run = subprocess.Popen(['./' + src + '.exe'], stdout=subprocess.PIPE, universal_newlines=True)

    gccLines = []

    # for line in run.stdout:
    #	gccLines.append(line)

    gccLines = run.communicate()[0].split('\n')

    stdout.write("compiled code output " + str(len(gccLines)) + " lines\n")
    stdout.write("compiled code returned " + str(run.returncode) + "\n")

    stdout.write("run scrip\n")
    scrip = subprocess.Popen([scrip_exe, src + '.cpp'], stdout=subprocess.PIPE, stderr=subprocess.PIPE,
                             universal_newlines=True)
    stdout.write("...OK\n")

    scripOut = False
    scripLines = []

    listing += '// Source:\n'
    if comp.returncode == 0:
        F = open(src + '.cpp', 'r')
        for l in F:
            listing += l

    listing += '\n// Output:\n/*\n'

    scripLines, scripStderr = map(lambda s: s.split('\n'), scrip.communicate())

    err += "\n*********************\n" + src + ".cpp\n*********************\n"
    err += "\n".join(scripStderr)

    listing += '\n*/\n'

    stdout.write("scrip code output " + str(len(scripLines)) + " lines\n")
    stdout.write("scrip code returned " + str(scrip.returncode) + "\n")

    if len(scripLines) != len(gccLines):
        ok = False
    if scrip.returncode != run.returncode:
        ok = False

    for i in range(0, max(len(scripLines), len(gccLines))):
        gccline = ''
        if i < len(gccLines):
            gccline = gccLines[i].rstrip()

        scrline = ''
        if i < len(scripLines):
            scrline = scripLines[i].rstrip()

        if scrline != gccline:
            ok = False

        stdout.write("\033[38;5;12m")
        stdout.write("\033[48;5;0m")
        stdout.write('g++>' + gccline)
        stdout.write("\033[0m")
        stdout.write("\n")
        stdout.write("\033[38;5;7m")
        if not ok:
            stdout.write("\033[48;5;0m")
        stdout.write('scr>' + scrline)
        stdout.write("\033[0m")
        stdout.write("\n")

    if ok:
        report += src + ': OK\n'
        oks += 1
    else:
        report += src + ': FAIL\n'
        fails += 1

report += '\n' + str(oks) + ' OK\n' + str(fails) + ' failed\n'

stdout.write("\033[0m")

stdout.write(report)
G = open('0list.h', 'w')
G.write(listing)
H = open('0report.txt', 'w')
H.write(report)
E = open('0stderr', 'w')
E.write(err)
