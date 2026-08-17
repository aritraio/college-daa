const readline = require('readline');

const rl = readline.createInterface({ input: process.stdin, output: process.stdout });

let lines = [];
rl.on('line', (line) => {
    lines.push(line);
    if (lines.length === 2) {
        const text = lines[0];
        const pattern = lines[1];
        const n = text.length, m = pattern.length;
        let found = false;
        for (let i = 0; i <= n - m; i++) {
            let j = 0;
            while (j < m && text[i + j] === pattern[j]) j++;
            if (j === m) {
                console.log(`Pattern found at index ${i}`);
                found = true;
            }
        }
        if (!found) console.log('not found');
        rl.close();
    }
});