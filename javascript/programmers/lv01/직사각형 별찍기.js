// https://school.programmers.co.kr/learn/courses/30/lessons/12969
process.stdin.setEncoding('utf8');
process.stdin.on('data', (data) => {
  const n = data.split(' ');
  let a = Number(n[0]),
    b = Number(n[1]);

  while (b--) {
    console.log('*'.repeat(a));
  }
});
