function solution(progresses, speeds) {
  const res = [];
  const daysLeft = progresses.map((progress, index) =>
    Math.ceil((100 - progress) / speeds[index])
  );
  let count = 0;
  let maxDay = daysLeft[0];

  for (let i = 0; i < progresses.length; ++i) {
    if (daysLeft[i] <= maxDay) {
      count++;
    } else {
      res.push(count);
      count = 1;
      maxDay = daysLeft[i];
    }
  }
  res.push(count);

  return res;
}
