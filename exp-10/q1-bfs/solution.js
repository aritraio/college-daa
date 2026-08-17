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
    const adj = Array.from({ length: n + 1 }, () => []);
    for (let i = 0; i < m; i++) {
        const u = data[idx++], v = data[idx++];
        adj[u].push(v);
        adj[v].push(u);
    }
    const s = data[idx++];

    for (let i = 1; i <= n; i++) adj[i].sort((a, b) => a - b);

    const visited = new Array(n + 1).fill(false);
    const queue = [s];
    visited[s] = true;
    const order = [];
    while (queue.length) {
        const u = queue.shift();
        order.push(u);
        for (const v of adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                queue.push(v);
            }
        }
    }
    console.log('BFS Traversal: ' + order.join(' '));
});