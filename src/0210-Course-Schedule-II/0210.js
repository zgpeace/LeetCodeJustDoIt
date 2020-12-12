var findOrder = function(n, prerequisites) {
    let g = {};
    let d = new Array(n), vis = new Array(n), res = [], q = [];
    d.fill(0); vis.fill(0);
    for (let it of prerequisites) {
        if (g[it[1]])
            g[it[1]].push(it[0]);
        else g[it[1]] = [it[0]];
        d[it[0]]++;
    }
    
    for (let i = 0; i < n; i++) {
        if (d[i] == 0) {
            q.push(i);
            vis[i] = 1;
        }
    }
    
    while (q.length) {
        let cur = q.shift();
        res.push(cur);
        n--;
        for (let i of g[cur] || []) {
            d[i]--;
            if (!vis[i] && d[i] == 0) {
                vis[i] = 1;
                q.push(i);
            }
        }
    }
    return n == 0 ? res : [];
};