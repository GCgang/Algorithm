function solution(N, stages) {
  let challengers = new Array(N + 2).fill(0);

  // 스테이지별 도전자 수 구하기
  for (const stage of stages) {
    challengers[stage] += 1;
  }

  // 실패율 구하기
  let fails = [];
  let total = stages.length;
  for (let i = 1; i <= N; ++i) {
    if (challengers[i] === 0) {
      fails.push({ stage: i, failRate: 0 });
      continue;
    } else {
      let failRate = challengers[i] / total;
      fails.push({ stage: i, failRate: failRate });
      total -= challengers[i];
    }
  }

  // 실패율이 높은 스테이지부터 내림차순으로 정렬
  fails.sort((a, b) => b.failRate - a.failRate);

  // 스테이지 번호만 반환
  return fails.map((f) => f.stage);
}
