// https://school.programmers.co.kr/learn/courses/30/lessons/81301

function solution(s) {
  const numberMap = {
    zero: '0',
    one: '1',
    two: '2',
    three: '3',
    four: '4',
    five: '5',
    six: '6',
    seven: '7',
    eight: '8',
    nine: '9',
  };

  for (const [word, digit] of Object.entries(numberMap)) {
    s = s.split(word).join(digit);
  }
  return parseInt(s);
}

function solution2(s) {
  const numberMap = {
    zero: '0',
    one: '1',
    two: '2',
    three: '3',
    four: '4',
    five: '5',
    six: '6',
    seven: '7',
    eight: '8',
    nine: '9',
  };

  return Number(
    s.replace(/zero|one|two|three|four|five|six|seven|eight|nine/g, (match) => {
      return numberMap[match];
    })
  );
}
