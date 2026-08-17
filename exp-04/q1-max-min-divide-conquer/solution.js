const readline = require('readline');

const rl = readline.createInterface({ input: process.stdin, output: process.stdout });

function findMinMax(a, lo, hi) {
    if (lo === hi) return [a[lo], a[lo]];
    if (hi === lo + 1) return a[lo] < a[hi] ? [a[lo], a[hi]] : [a[hi], a[lo]];
    const mid = Math.floor((lo + hi) / 2);
    const [minL, maxL] = findMinMax(a, lo, mid);
    const [minR, maxR] = findMinMax(a, mid + 1, hi);
    return [Math.min(minL, minR), Math.max(maxL, maxR)];
}

let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0], 10);
        const a = lines[1].split(/\s+/).map(Number);
        const [min, max] = findMinMax(a, 0, n - 1);
        console.log(`Min: ${min}`);
        console.log(`Max: ${max}`);
        rl.close();
    }
});