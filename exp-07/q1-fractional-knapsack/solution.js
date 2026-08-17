const fs = require("fs");

const data = fs.readFileSync(0, "utf-8").trim().split(/\s+/).map(Number);
const n = data[0];
let W = data[1];

const items = [];
for (let i = 0; i < n; i++) {
    items.push({ weight: data[2 + 2 * i], profit: data[3 + 2 * i] });
}

items.sort((a, b) => b.profit / b.weight - a.profit / a.weight);

let total = 0;
for (const item of items) {
    if (item.weight <= W) {
        total += item.profit;
        W -= item.weight;
    } else {
        total += item.profit * (W / item.weight);
        W = 0;
    }
}

console.log(total.toFixed(2));