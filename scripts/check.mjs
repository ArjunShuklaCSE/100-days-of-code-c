// Compiles every solution and runs the sample test cases from its header comment.
//
//   node scripts/check.mjs            (needs gcc on PATH)
//
// A header looks like:  Input 1: <stdin lines>  Output 1: <expected stdout>
// Output is compared line by line, ignoring trailing spaces and blank lines at the start or end.
import { execFileSync, spawnSync } from 'node:child_process';
import { readdirSync, readFileSync, mkdtempSync } from 'node:fs';
import { join } from 'node:path';
import { tmpdir } from 'node:os';

// Sample answers in the original problem set that are wrong or aren't real output. The solutions are right.
const errata = {
  'Day-02/Q4.c:1': 'the sample uses pi = 3.14 for the circumference but full pi for the area',
  'Day-05/Q9.c:2': 'compound interest on 5000 at 7% for 3 years is 1125.22, not 1125.76',
  'Day-22/Q44.c:1': '1 + 3/4 + 5/6 = 2.58, not 3.3',
  'Day-23/Q45.c:1': '2/3 + 4/7 + 6/11 = 1.78, not 1.56',
  'Day-23/Q45.c:2': 'the first five terms sum to 2.84, not 2.22',
  'Day-25/Q50.c:2': 'the sample is a note, not an output',
  'Day-26/Q52.c:1': 'the sample describes the pattern instead of showing it',
  'Day-27/Q54.c:1': 'the sample describes the pattern instead of showing it',
};

const build = mkdtempSync(join(tmpdir(), 'c100-'));
const stripBlankEdges = text => text.replace(/^\n+|\n+$/g, '');
const normalize = text =>
  stripBlankEdges(
    text
      .replace(/\r/g, '')
      .split('\n')
      .map(line => line.trimEnd())
      .join('\n'),
  );
let passed = 0;
let failed = 0;
let skipped = 0;
let untested = 0;

for (const day of readdirSync('.').filter(name => /^Day-\d+$/.test(name)).sort()) {
  for (const file of readdirSync(day).filter(name => name.endsWith('.c')).sort()) {
    const path = `${day}/${file}`;
    const source = readFileSync(path, 'utf8').replace(/\r/g, '');
    const exe = join(build, `${day}-${file}.exe`);
    try {
      execFileSync('gcc', ['-std=c11', '-O1', '-o', exe, path, '-lm'], { stdio: 'pipe' });
    } catch (error) {
      failed++;
      console.log(`FAIL  ${path}: does not compile\n${error.stderr}`);
      continue;
    }
    const header = source.match(/\/\*([\s\S]*?)\*\//)?.[1] ?? '';
    const cases = [
      ...header.matchAll(
        /Input\s*(\d+)\s*:[ \t]*\n([\s\S]*?)\n\s*Output\s*\1\s*:[ \t]*\n([\s\S]*?)(?=\n\s*Input\s*\d+\s*:|\n\s*(?:Explanation|Note)\b|$)/g,
      ),
    ];
    if (!cases.length) {
      untested++;
      continue;
    }
    for (const [, n, input, output] of cases) {
      if (errata[`${path}:${n}`]) {
        skipped++;
        continue;
      }
      const run = spawnSync(exe, { input: `${stripBlankEdges(input)}\n`, encoding: 'utf8', timeout: 5000 });
      if (normalize(run.stdout ?? '') === normalize(output)) passed++;
      else {
        failed++;
        console.log(`FAIL  ${path} case ${n}`);
        console.log(`  expected: ${JSON.stringify(normalize(output))}`);
        console.log(`  got:      ${JSON.stringify(normalize(run.stdout ?? ''))}`);
      }
    }
  }
}
console.log(
  `\n${passed} sample cases passed, ${failed} failed, ${skipped} skipped (errata in the problem set), ${untested} files without sample cases`,
);
process.exit(failed ? 1 : 0);
