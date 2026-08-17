const readline = require('readline');

const rl = readline.createInterface({ input: process.stdin });

const MAX = 100;
const s = Array.from({ length: MAX }, () => new Array(MAX).fill(0));
let tokens = [];

function printOrder(i, j) {
    if (i === j) {
        process.stdout.write(`A${i}`);
        return;
    }
    process.stdout.write('(');
    printOrder(i, s[i][j]);
    printOrder(s[i][j] + 1, j);
    process.stdout.write(')');
}

rl.on('line', (line) => {
    tokens = tokens.concat(line.trim().split(/\s+/).map(Number));
});

rl.on('close', () => {
    const n = tokens[0];
    const p = tokens.slice(1, n + 2);
    const m = Array.from({ length: MAX }, () => new Array(MAX).fill(0));

    for (let length = 2; length <= n; length++) {
        for (let i = 1; i <= n - length + 1; i++) {
            const j = i + length - 1;
            m[i][j] = Infinity;
            for (let k = i; k < j; k++) {
                const cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }

    console.log(`Minimum cost: ${m[1][n]}`);
    process.stdout.write('Optimal parenthesization: ');
    printOrder(1, n);
    console.log();
});
