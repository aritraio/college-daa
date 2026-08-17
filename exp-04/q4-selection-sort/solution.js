const readline = require('readline');

const rl = readline.createInterface({ input: process.stdin, output: process.stdout });

function selectionSort(a) {
    for (let i = 0; i < a.length - 1; i++) {
        let minIdx = i;
        for (let j = i + 1; j < a.length; j++) {
            if (a[j] < a[minIdx]) minIdx = j;
        }
        [a[i], a[minIdx]] = [a[minIdx], a[i]];
    }
}

let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0], 10);
        const a = lines[1].split(/\s+/).map(Number);
        selectionSort(a);
        console.log(a.join(' '));
        rl.close();
    }
});