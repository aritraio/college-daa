const fs = require("fs");

const data = fs.readFileSync(0, "utf-8").trim().split(/\s+/).map(Number);

const n = data[0];
const arr = data.slice(1, n + 1);
const key = data[n + 1];

let index = -1;
for (let i = 0; i < n; i++) {
    if (arr[i] === key) {
        index = i;
        break;
    }
}

if (index === -1) {
    console.log("Element not found");
} else {
    console.log(`Element found at index ${index}`);
}