function solution(s) {
  const sets = s
    .slice(2, -2)
    .split('},{')
    .map((set) => set.split(',').map(Number));

  sets.sort((a, b) => a.length - b.length);

  const result = [];
  const seen = new Set();

  for (let set of sets) {
    for (let num of set) {
      if (!seen.has(num)) {
        seen.add(num);
        result.push(num);
      }
    }
  }

  return result;
}
