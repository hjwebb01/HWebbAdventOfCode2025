import { readFileSync } from "fs";

function adventDay2(range) {
  const bounds = range.split("-").map(Number); // Split the range into lower and upper bounds
  var badID = 0;
  for (let i = bounds[0]; i <= bounds[1]; i++) {
    // Loop through each number in the range
    const numStr = i.toString();
    if (numStr.length % 2 != 0) continue; // Skip if the number of digits is odd

    var l = 0;
    var mid = numStr.length / 2;
    var valid = true;
    while (mid < numStr.length) {
      if (numStr[l] != numStr[mid]) {
        valid = false;
      }
      l = l + 1;
      mid = mid + 1;
    }
    if (valid) {
      badID = badID + i;
    }
  }
  return badID;
}

function main() {
  const input = readFileSync("./input.txt", "utf8");
  var res = 0;
  input.split(",").forEach((line) => {
    // Split by comma
    res = res + adventDay2(line);
  });
  console.log(res); // print result
}

main();
