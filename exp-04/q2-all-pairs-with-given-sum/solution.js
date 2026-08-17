const readline = require('readline');

const rl = readline.createInterface({ input: process.stdin, output: process.stdout });

let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const n = parseInt(lines[0], 10);
        const a = lines[1].split(/\s+/).map(Number);
        const s = parseInt(lines[2], 10);
        let found = false;
        for (let i = 0; i < n; i++) {
            for (let j = i + 1; j < n; j++) {
                if (a[i] + a[j] === s) {
                    console.log(`(${i}, ${j})`);
                    found = true;
                }
            }
        }
        if (!found) console.log('No pairs found');
        rl.close();
    }
});