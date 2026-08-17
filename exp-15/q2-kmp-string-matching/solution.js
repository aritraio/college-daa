const readline = require('readline');

const rl = readline.createInterface({ input: process.stdin, output: process.stdout });

function computeLPS(p) {
    const m = p.length;
    const lps = new Array(m).fill(0);
    let len = 0, i = 1;
    while (i < m) {
        if (p[i] === p[len]) {
            len++;
            lps[i] = len;
            i++;
        } else if (len !== 0) {
            len = lps[len - 1];
        } else {
            lps[i] = 0;
            i++;
        }
    }
    return lps;
}

let lines = [];
rl.on('line', (line) => {
    lines.push(line);
    if (lines.length === 2) {
        const text = lines[0];
        const pattern = lines[1];
        const n = text.length, m = pattern.length;
        const lps = computeLPS(pattern);
        let i = 0, j = 0;
        let found = false;
        while (i < n) {
            if (pattern[j] === text[i]) {
                i++;
                j++;
            }
            if (j === m) {
                console.log(`Pattern found at index ${i - j}`);
                found = true;
                j = lps[j - 1];
            } else if (i < n && pattern[j] !== text[i]) {
                if (j !== 0) j = lps[j - 1];
                else i++;
            }
        }
        if (!found) console.log('not found');
        rl.close();
    }
});
