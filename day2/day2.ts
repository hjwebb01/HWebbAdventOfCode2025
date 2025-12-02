import fs from 'fs';

function adventDay2(range){
  return 0;
}



function main() {
  const input = fs.readFileSync('day2/input.txt', 'utf8');
  var res = 0;
  input.split(',').forEach(line => { // Split by comma
     res = res + adventDay2(line);
  })
  console.log(res); // print result
}
