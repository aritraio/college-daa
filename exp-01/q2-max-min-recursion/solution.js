const readline = require('readline');

const rl = readline.createInterface({ input: process.stdin, output: process.stdout });

function findMinMax(arr, n) {
    if (n === 1) return [arr[0], arr[0]];
    const [curMin, curMax] = findMinMax(arr, n - 1);
    return [Math.min(curMin, arr[n - 1]), Math.max(curMax, arr[n - 1])];
}

const lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0], 10);
        const arr = lines[1].split(/\s+/).map(Number);
        const [minVal, maxVal] = findMinMax(arr, n);
        console.log(`Min: ${minVal}`);
        console.log(`Max: ${maxVal}`);
        rl.close();
    }
});