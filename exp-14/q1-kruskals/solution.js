const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

function find(parent, x) {
    if (parent[x] !== x)
        parent[x] = find(parent, parent[x]);
    return parent[x];
}

const lines = [];
rl.on('line', (line) => lines.push(line.trim()));
rl.on('close', () => {
    const nums = lines.join(' ').split(/\s+/).map(Number);
    let idx = 0;
    const n = nums[idx++];
    const m = nums[idx++];

    const edges = [];
    for (let i = 0; i < m; i++) {
        const u = nums[idx++];
        const v = nums[idx++];
        const w = nums[idx++];
        edges.push({ u, v, w });
    }

    edges.sort((a, b) => a.w - b.w);

    const parent = Array.from({ length: n + 1 }, (_, i) => i);

    console.log('Edges in MST:');
    let total = 0, count = 0;
    for (const e of edges) {
        if (count === n - 1) break;
        const ru = find(parent, e.u);
        const rv = find(parent, e.v);
        if (ru !== rv) {
            parent[ru] = rv;
            console.log(`${e.u} - ${e.v} (${e.w})`);
            total += e.w;
            count++;
        }
    }

    console.log(`Total weight of MST: ${total}`);
});
