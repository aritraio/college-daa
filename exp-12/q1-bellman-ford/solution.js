const fs = require("fs");

const data = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let idx = 0;
const n = data[idx++];
const m = data[idx++];

const edges = [];
for (let i = 0; i < m; i++) {
  edges.push([data[idx++], data[idx++], data[idx++]]);
}
const s = data[idx++];

const INF = 999999;
const dist = new Array(n + 1).fill(INF);
dist[s] = 0;

for (let i = 1; i <= n - 1; i++) {
  let changed = false;
  for (const [u, v, w] of edges) {
    if (dist[u] !== INF && dist[u] + w < dist[v]) {
      dist[v] = dist[u] + w;
      changed = true;
    }
  }
  if (!changed) break;
}

for (const [u, v, w] of edges) {
  if (dist[u] !== INF && dist[u] + w < dist[v]) {
    console.log("Negative cycle detected");
    process.exit(0);
  }
}

console.log(`Shortest distances from source ${s}:`);
for (let i = 1; i <= n; i++) {
  console.log(`${i}: ${dist[i] === INF ? "INF" : dist[i]}`);
}
