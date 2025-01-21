// https://school.programmers.co.kr/learn/courses/30/lessons/86051
// function solution(numbers) {
//     const cntArr = new Array(10).fill(0);

//     numbers.forEach(num => cntArr[num]++)

//     return cntArr.reduce((acc, cur, i) => acc + (cur === 0 ? i : 0), 0);

// }

// function solution(numbers) {
//     let sum = 0;

//     for (let i = 0; i <= 9; i++) {
//         if (!numbers.includes(i)) {
//             sum += i;
//         }
//     }
//     return sum;
// }

// function solution(numbers) {
//     const totalSum = Array.from({length : 10}, (_, i) => i).reduce((acc, cur) => acc + cur, 0);
//     return totalSum - numbers.reduce((acc, cur) => acc + cur, 0)
// }

function solution(numbers) {
  const allNums = new Set(Array.from({ length: 10 }, (_, i) => i));

  numbers.forEach((num) => allNums.delete(num));

  return Array.from(allNums).reduce((acc, cur) => acc + cur, 0);
}
