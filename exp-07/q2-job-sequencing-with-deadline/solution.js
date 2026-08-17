const fs = require("fs");

const data = fs.readFileSync(0, "utf-8").trim().split(/\s+/).map(Number);
const n = data[0];

const jobs = [];
let maxD = 0;
for (let i = 0; i < n; i++) {
    const id = data[1 + 3 * i];
    const deadline = data[2 + 3 * i];
    const profit = data[3 + 3 * i];
    jobs.push({ id, deadline, profit });
    if (deadline > maxD) maxD = deadline;
}

jobs.sort((a, b) => b.profit - a.profit);

const slot = new Array(maxD).fill(0);
let total = 0;
for (const job of jobs) {
    for (let j = job.deadline - 1; j >= 0; j--) {
        if (slot[j] === 0) {
            slot[j] = job.id;
            total += job.profit;
            break;
        }
    }
}

const selected = slot.filter((s) => s !== 0);
console.log("Selected jobs:", selected.join(" "));
console.log("Total profit:", total);