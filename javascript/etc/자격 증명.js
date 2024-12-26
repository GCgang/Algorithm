// https://jsalgo.co.kr/?page=1

function solution(data) {
  let result = '';

  data.forEach((line) => {
    let binary = '';
    for (let char of line) {
      if (char === '+') {
        binary += '1';
      } else if (char === '-') {
        binary += '0';
      }
    }

    const decimal = parseInt(binary, 2);
    result += String.fromCharCode(decimal);
  });

  return result;
}

const input1 = [' + - - + - + - ', ' + + + - + - + ', ' + + - + + + - '];
console.log(solution(input1)); // 출력: 'Jun'
