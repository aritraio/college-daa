const fs = require("fs");

const data = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let idx = 0;
const n = data[idx++];

const INF = 999999;
const dist = [];
for (let i = 0; i < n; i++) {
  const row = [];
  for (let j = 0; j < n; j++) {
    row.push(data[idx++]);
  }
  dist.push(row);
}

for (let k = 0; k < n; k++) {
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      if (
        dist[i][k] !== INF &&
        dist[k][j] !== INF &&
        dist[i][k] + dist[k][j] < dist[i][j]
      ) {
        dist[i][j] = dist[i][k] + dist[k][j];
      }
    }
  }
}

for (let i = 0; i < n; i++) {
  const row = [];
  for (let j = 0; j < n; j++) {
    row.push(dist[i][j] === INF ? "INF" : dist[i][j]);
  }
  console.log(row.join(" "));
}
