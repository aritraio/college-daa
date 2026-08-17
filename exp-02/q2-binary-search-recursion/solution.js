const fs = require("fs");

function binarySearch(arr, low, high, key) {
    if (low > high) {
        return -1;
    }

    const mid = low + Math.floor((high - low) / 2);

    if (arr[mid] === key) {
        return mid;
    } else if (arr[mid] > key) {
        return binarySearch(arr, low, mid - 1, key);
    } else {
        return binarySearch(arr, mid + 1, high, key);
    }
}

const data = fs.readFileSync(0, "utf-8").trim().split(/\s+/).map(Number);

const n = data[0];
const arr = data.slice(1, n + 1);
const key = data[n + 1];

const index = binarySearch(arr, 0, n - 1, key);

if (index === -1) {
    console.log("Element not found");
} else {
    console.log(`Element found at index ${index}`);
}