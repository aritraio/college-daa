const fs = require("fs");

const INF = 1000000000;
const MAX = 100;

const data = fs.readFileSync(0, "utf-8").trim().split(/\s+/).map(Number);
let idx = 0;
const n = data[idx++];
const m = data[idx++];

const adj = Array.from({ length: MAX }, () => new Array(MAX).fill(INF));
for (let i = 0; i < m; i++) {
  const u = data[idx++];
  const v = data[idx++];
  const w = data[idx++];
  adj[u][v] = w;
}
const s = data[idx++];

const dist = new Array(MAX).fill(INF);
const visited = new Array(MAX).fill(false);
dist[s] = 0;

for (let count = 0; count < n; count++) {
  let u = -1;
  let min = INF;
  for (let i = 1; i <= n; i++) {
    if (!visited[i] && dist[i] < min) {
      min = dist[i];
      u = i;
    }
  }
  if (u === -1) break;
  visited[u] = true;
  for (let v = 1; v <= n; v++) {
    if (!visited[v] && adj[u][v] < INF && dist[u] + adj[u][v] < dist[v]) {
      dist[v] = dist[u] + adj[u][v];
    }
  }
}

for (let i = 1; i <= n; i++) {
  console.log(`Distance from ${s} to ${i}: ${dist[i]}`);
}
