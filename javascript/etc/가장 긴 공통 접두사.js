// input: strs = ['floer', 'flow', 'flight']
// output: 'fl'

// input: strs = ['dog', 'racecar', 'car']
// output: ''

function solution(strs) {
  let result = '';

  if (strs === null || strs.length == 0) {
    return result;
  }

  for (let i = 0; i < strs[0].length; ++i) {
    const char = strs[0][i];

    for (let j = 1; j < strs.length; ++j) {
      if (strs[j][i] !== char) {
        return result;
      }
    }
    result += char;
  }
  return result;
}

const strs = ['floer', 'flow', 'flight'];
const strs2 = ['dog', 'racecar', 'car'];

console.log(solution(strs)); // fl
console.log(solution(strs2)); // ''
