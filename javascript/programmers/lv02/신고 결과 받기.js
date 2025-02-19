// https://school.programmers.co.kr/learn/courses/30/lessons/92334
function solution(id_list, report, k) {
  const reports = [...new Set(report)].map((r) => r.split(' '));

  const reportCnt = new Map();
  const userReportMap = new Map();

  for (const id of id_list) {
    reportCnt.set(id, 0);
    userReportMap.set(id, []);
  }

  for (const [reporter, reported] of reports) {
    userReportMap.get(reporter).push(reported);
    reportCnt.set(reported, reportCnt.get(reported) + 1);
  }

  const banUsers = new Set(id_list.filter((user) => reportCnt.get(user) >= k));

  const mailCounts = id_list.map((user) => {
    let cnt = 0;

    for (const reported of userReportMap.get(user)) {
      if (banUsers.has(reported)) {
        cnt++;
      }
    }
    return cnt;
  });

  return mailCounts;
}
