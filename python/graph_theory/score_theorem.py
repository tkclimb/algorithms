import numpy as np
import networkx as nx
import matplotlib.pyplot as plt


def dijkstra(M, S):
    d = {}
    prev = {}
    V = set(range(1, len(M)+1))

    for e in V:
        d[e] = 10000000
        if e == S:
            d[e] = 0
        prev[e] = None

    Q = d.copy()

    while not len(Q) == 0:
        u = min(Q, key=Q.get)
        del Q[u]


if __name__ == "__main__":
    A = list('023000200200300440024005004004000540')
    A = np.asarray(A, dtype=float)
    n = int(len(A)**0.5)
    M = np.reshape(A, (n, n))
    # A = dijkstra(M, 1)
    G = nx.Graph(M)
    # nx.draw_networkx(G)
    # plt.show()
    # print(G.nodes)
    # print(G.edges)
    # weight = [G[f][t] for f, t in G.edges]
    # weight = [G[e] for e in G.edges]
    # G[1][0]['name'] = 'one'
    # G.nodes[1] = 'one'
    # print(G[1])
    # print(weight)
    # print(G.degree(3))
    # G = nx.karate_club_graph()
    # nx.draw_networkx(G)
    # plt.show()
    # max_degree = np.argmax([x for i, x in G.degree])
    # print(max_degree)
