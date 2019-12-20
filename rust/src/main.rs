// use std::rand::task_rng;
use rand::distributions::{Distribution, Uniform};
use std::cmp;
use std::time::{Duration, Instant};
use std::vec::Vec;

macro_rules! measure {
    ( $x:expr) => {{
        let start = Instant::now();
        let result = $x;
        let end = start.elapsed();
        println!(
            "exec time: {}.{}",
            end.as_secs(),
            end.subsec_nanos() / 1_000_000
        );
        result
    }};
}

fn cut_rod(p: &mut [i64], n: usize) -> i64 {
    if n == 0 {
        return 0;
    }
    let mut q = core::i64::MIN;
    for i in 0..n {
        q = cmp::max(q, p[i] + cut_rod(p, n - (i + 1)))
    }
    q
}

fn memorized_cut_rod(p: &mut [i64], n: usize) -> Vec<i64> {
    let mut r: Vec<i64> = Vec::new();
    r.resize_with(n + 1, || core::i64::MIN);
    memoized_cut_rod_aux(p, n, &mut r);
    r
}

fn memoized_cut_rod_aux(p: &mut [i64], n: usize, r: &mut [i64]) -> i64 {
    if r[n] >= 0 {
        return r[n];
    }
    let mut q: i64 = core::i64::MIN;
    if n == 0 {
        q = 0;
    } else {
        for i in 0..n {
            q = cmp::max(q, p[i] + memoized_cut_rod_aux(p, n - (i + 1), r));
        }
    }
    r[n] = q;
    q
}

fn bottom_up_cut_rod(p: &mut [i64], n: usize) -> Vec<i64> {
    let mut r: Vec<i64> = Vec::new();
    r.resize_with(n + 1, || 0);
    for j in 1..n + 1 {
        let mut q = core::i64::MIN;
        for i in 0..j {
            q = cmp::max(q, p[i] + r[j - (i + 1)]);
        }
        r[j] = q;
    }
    r
}

fn extend_bottom_up_cut_rod(p: &mut [i64], n: usize) -> (Vec<i64>, Vec<usize>) {
    let mut r: Vec<i64> = Vec::new();
    let mut s: Vec<usize> = Vec::new();
    r.resize_with(n + 1, || 0);
    s.resize_with(n + 1, || 0);
    for j in 1..n + 1 {
        let mut q = core::i64::MIN;
        for i in 0..j {
            let x = p[i] + r[j - (i + 1)];
            if x > q {
                q = x;
                s[j] = i;
            }
        }
        r[j] = q;
    }
    (r, s)
}

fn rand_int() -> i64 {
    let step = Uniform::new(0, 50);
    let mut rng = rand::thread_rng();
    step.sample(&mut rng)
}

fn main() {
    let mut p = Vec::new();
    let n = 10;
    p.resize_with(n, || rand_int());
    let r = cut_rod(&mut p, n);
    let r1 = memorized_cut_rod(&mut p, n);
    let r2 = bottom_up_cut_rod(&mut p, n);
    let (r3, s) = extend_bottom_up_cut_rod(&mut p, n);
    assert!(r == r1[n]);
    assert!(r1 == r2);
    assert!(r1 == r3);
    println!("{:?}", s)

    // for measuring time
    // let r1 = measure!({
    //     p.resize_with(n, rand_int);
    //     println!("try: n = {}", n);
    //     bottom_up_cut_rod(&mut p, n)
    // });
}
