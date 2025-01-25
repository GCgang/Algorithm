// https://school.programmers.co.kr/learn/courses/30/lessons/17682
function solution(dartResult) {
  const scores = [];
  let currentScore = 0; // 현재 점수

  for (let i = 0; i < dartResult.length; i++) {
    const char = dartResult[i];

    // 숫자 처리
    if (!isNaN(char)) {
      if (char === '1' && dartResult[i + 1] === '0') {
        // 숫자가 10인 경우
        currentScore = 10;
        i++; // 10은 두 자리이므로 다음 문자 건너뜀
      } else {
        currentScore = Number(char);
      }
    }
    // 보너스 처리
    else if (char === 'S') {
      scores.push(currentScore ** 1);
    } else if (char === 'D') {
      scores.push(currentScore ** 2);
    } else if (char === 'T') {
      scores.push(currentScore ** 3);
    }
    // 옵션 처리
    else if (char === '*') {
      const len = scores.length;
      scores[len - 1] *= 2; // 현재 점수 2배
      if (len > 1) {
        scores[len - 2] *= 2; // 이전 점수도 2배
      }
    } else if (char === '#') {
      scores[scores.length - 1] *= -1; // 현재 점수 마이너스
    }
  }

  return scores.reduce((sum, cur) => sum + cur, 0); // 총합 계산
}

// 정규식
function solution2(dartResult) {
  const regex = /(\d+)([SDT])([*#]?)/g; // 점수, 보너스, 옵션을 분리하기 위한 정규식
  const scores = []; // 각 점수 세트를 저장할 배열

  let match;
  while ((match = regex.exec(dartResult)) !== null) {
    let [_, score, bonus, option] = match; // 정규식 매칭 결과를 변수에 할당
    score = Number(score); // 점수를 숫자로 변환

    // 보너스 처리
    if (bonus === 'S') score **= 1; // Single
    if (bonus === 'D') score **= 2; // Double
    if (bonus === 'T') score **= 3; // Triple

    // 옵션 처리
    if (option === '*') {
      score *= 2; // 현재 점수 2배
      if (scores.length > 0) {
        scores[scores.length - 1] *= 2; // 이전 점수도 2배
      }
    } else if (option === '#') {
      score *= -1; // 현재 점수 음수화
    }

    scores.push(score); // 점수를 배열에 추가
  }

  // 최종 점수 합산
  return scores.reduce((sum, cur) => sum + cur, 0);
}
