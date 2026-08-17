const fs = require("fs");

function minKey(key, mstSet, n) {
    let min = Infinity, minIndex = -1;
    for (let v = 0; v < n; v++)
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    return minIndex;
}

function main() {
    const input = fs.readFileSync("/dev/stdin", "utf8").trim().split(/\s+/).map(Number);
    let idx = 0;
    const n = input[idx++];
    const m = input[idx++];

    const graph = Array.from({ length: n }, () => Array(n).fill(0));

    for (let i = 0; i < m; i++) {
        const u = input[idx++], v = input[idx++], w = input[idx++];
        graph[u - 1][v - 1] = w;
        graph[v - 1][u - 1] = w;
    }

    const parent = Array(n).fill(-1);
    const key = Array(n).fill(Infinity);
    const mstSet = Array(n).fill(false);

    key[0] = 0;

    let totalWeight = 0;
    for (let count = 0; count < n; count++) {
        const u = minKey(key, mstSet, n);
        mstSet[u] = true;
        totalWeight += key[u];

        for (let v = 0; v < n; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }

    let output = "";
    for (let v = 1; v < n; v++)
        output += `Edge ${parent[v] + 1}-${v + 1} weight ${key[v]}\n`;
    output += `Total weight of MST: ${totalWeight}\n`;
    process.stdout.write(output);
}

main();
