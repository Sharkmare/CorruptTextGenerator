function corruptme(r) {
    for (corrupters = ["0", "@", "&", "%", "$", "§"], Amax = r.length, ammount = Amax / 10, i = 0; i < ammount; i++) {
        let t = corrupters[rng(corrupters.length)],
            n = rng(Amax);
        " " != r[n] ? r = rep(r, n, t) : i--
    }
    return console.log(r)
}

function rng(r) {
    return Math.floor(Math.random() * r)
}

function rep(r, t, n) {
    return r = setCharAt(r, t, n)
}

function setCharAt(r, t, n) {
    return t > r.length - 1 ? r : r.substring(0, t) + n + r.substring(t + 1)
}
