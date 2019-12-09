use std::vec::Vec;
use std::cmp;

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

fn memorized_cut_rod(p: &mut [i64], n: usize) ->i64 {
    let mut r: Vec<i64> = Vec::new();
    r.resize_with(n + 1, || { core::i64::MIN });
    return memoized_cut_rod_aux(p, n, &mut r)
}

fn memoized_cut_rod_aux(p: &mut [i64], n: usize, r: &mut [i64]) ->i64 {
    println!("n: {}", n);
    if r[n] >= 0 {
        println!("hit: memo");
        return r[n];
    }
    let mut q: i64 = core::i64::MIN;
    if n == 0 {
        println!("hit: n == 0");
        q = 0; 
    } else {
        for i in 0..n {
            println!("i: {}", i);
            q = cmp::max(q, p[i] + memoized_cut_rod_aux(p, n - (i + 1), r));
        }
    }
    r[n] = q; 
    q
}

fn main() {
    let mut p = vec![1, 3, 1];
    let n = p.len();
    // let r = cut_rod(&mut p, n);
    let r = memorized_cut_rod(&mut p, n);
    println!("r: {}", r)
}
