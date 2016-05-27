/*

223. Rectangle Area

Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Assume that the total area is never beyond the maximum possible value of int.

*/

class Solution {

public:

    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        if (A > C) std::swap(A,C);
        if (E > G) std::swap(E,G);
        if (B > D) std::swap(B,D);
        if (F > H) std::swap(F,H);
        int areaOne = (C-A) * (D-B);
        int areaTwo = (G-E) * (H-F);
        if (!areaOne)   return areaTwo;
        if (!areaTwo)   return areaOne;
        int left = A < E ? E : A;
        int right = C < G? C : G;
        int up = H < D ? H : D;
        int down = F < B ? B : F;
        int areaOverlap = left >= right? 
                                        0 : down >= up ? 
                                                        0 : (right - left) * (up - down);
        return (areaOne + areaTwo - areaOverlap);
    }
};

/* shorter:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
    {
        int x = min(G, C) > max(E, A) ? (min(G, C) - max(E, A)) : 0;
        int y = min(D, H) > max(B, F) ? (min(D, H) - max(B, F)) : 0;
        return (D - B) * (C - A) + (G - E) * (H - F) - x * y;
    }
*/
