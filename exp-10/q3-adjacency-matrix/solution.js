const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let lines = [];
rl.on('line', line => lines.push(line.trim()));
rl.on('close', () => {
    const data = lines.join(' ').split(/\s+/).map(Number);
    let idx = 0;
    const n = data[idx++], m = data[idx++];
    const mat = Array.from({ length: n + 1 }, () => new Array(n + 1).fill(0));
    for (let i = 0; i < m; i++) {
        const u = data[idx++], v = data[idx++];
        mat[u][v] = 1;
        mat[v][u] = 1;
    }
    for (let i = 1; i <= n; i++) {
        const row = [];
        for (let j = 1; j <= n; j++) row.push(mat[i][j]);
        console.log(row.join(' '));
    }
});