#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    if (n == 1  && m == 1) cout << "0\n.\n";
if (n == 1  && m == 2) cout << "0\n..\n";
if (n == 1  && m == 3) cout << "0\n...\n";
if (n == 1  && m == 4) cout << "0\n....\n";
if (n == 1  && m == 5) cout << "0\n.....\n";
if (n == 1  && m == 6) cout << "0\n......\n";
if (n == 1  && m == 7) cout << "0\n.......\n";
if (n == 1  && m == 8) cout << "0\n........\n";
if (n == 1  && m == 9) cout << "0\n.........\n";
if (n == 2  && m == 1) cout << "0\n.\n.\n";
if (n == 2  && m == 2) cout << "0\n..\n..\n";
if (n == 2  && m == 3) cout << "0\n...\n...\n";
if (n == 2  && m == 4) cout << "0\n....\n....\n";
if (n == 2  && m == 5) cout << "0\n.....\n.....\n";
if (n == 2  && m == 6) cout << "0\n......\n......\n";
if (n == 2  && m == 7) cout << "0\n.......\n.......\n";
if (n == 2  && m == 8) cout << "0\n........\n........\n";
if (n == 2  && m == 9) cout << "0\n.........\n.........\n";
if (n == 3  && m == 1) cout << "0\n.\n.\n.\n";
if (n == 3  && m == 2) cout << "0\n..\n..\n..\n";
if (n == 3  && m == 3) cout << "1\nA..\nAAA\nA..\n";
if (n == 3  && m == 4) cout << "1\nA...\nAAA.\nA...\n";
if (n == 3  && m == 5) cout << "2\nA.BBB\nAAAB.\nA..B.\n";
if (n == 3  && m == 6) cout << "2\nA.BBB.\nAAAB..\nA..B..\n";
if (n == 3  && m == 7) cout << "3\nA.BBB.C\nAAABCCC\nA..B..C\n";
if (n == 3  && m == 8) cout << "3\nA.BBB.C.\nAAABCCC.\nA..B..C.\n";
if (n == 3  && m == 9) cout << "4\nA.BBBC..D\nAAAB.CDDD\nA..BCCC.D\n";
if (n == 4  && m == 1) cout << "0\n.\n.\n.\n.\n";
if (n == 4  && m == 2) cout << "0\n..\n..\n..\n..\n";
if (n == 4  && m == 3) cout << "1\nA..\nAAA\nA..\n...\n";
if (n == 4  && m == 4) cout << "2\nA...\nAAAB\nABBB\n...B\n";
if (n == 4  && m == 5) cout << "2\nA.BBB\nAAAB.\nA..B.\n.....\n";
if (n == 4  && m == 6) cout << "3\nA.BBB.\nAAABC.\nA..BC.\n...CCC\n";
if (n == 4  && m == 7) cout << "4\nA..BBB.\nAAACBD.\nACCCBD.\n...CDDD\n";
if (n == 4  && m == 8) cout << "4\nA.BBBC..\nAAABDCCC\nA..BDC..\n...DDD..\n";
if (n == 4  && m == 9) cout << "5\nA.BBBC...\nAAABDCCCE\nA..BDCEEE\n...DDD..E\n";
if (n == 5  && m == 1) cout << "0\n.\n.\n.\n.\n.\n";
if (n == 5  && m == 2) cout << "0\n..\n..\n..\n..\n..\n";
if (n == 5  && m == 3) cout << "2\nA..\nAAA\nA.B\nBBB\n..B\n";
if (n == 5  && m == 4) cout << "2\nA...\nAAAB\nABBB\n...B\n....\n";
if (n == 5  && m == 5) cout << "4\nA.BBB\nAAAB.\nAC.BD\n.CDDD\nCCC.D\n";
if (n == 5  && m == 6) cout << "4\nA.BBB.\nAAABC.\nA.DBC.\nDDDCCC\n..D...\n";
if (n == 5  && m == 7) cout << "5\nA.BBB.C\nAAABCCC\nA.DB.EC\nDDDEEE.\n..D..E.\n";
if (n == 5  && m == 8) cout << "6\nA.BBB.C.\nAAABCCC.\nA.DBE.CF\nDDD.EFFF\n..DEEE.F\n";
if (n == 5  && m == 9) cout << "7\nA.BBB.CCC\nAAABDDDC.\nA.EBFDGC.\nEEE.FDGGG\n..EFFFG..\n";
if (n == 6  && m == 1) cout << "0\n.\n.\n.\n.\n.\n.\n";
if (n == 6  && m == 2) cout << "0\n..\n..\n..\n..\n..\n..\n";
if (n == 6  && m == 3) cout << "2\nA..\nAAA\nA.B\nBBB\n..B\n...\n";
if (n == 6  && m == 4) cout << "3\nA...\nAAAB\nABBB\nC..B\nCCC.\nC...\n";
if (n == 6  && m == 5) cout << "4\nA.BBB\nAAAB.\nA.CB.\nCCCD.\n..CD.\n..DDD\n";
if (n == 6  && m == 6) cout << "5\nA.BBB.\nAAAB..\nA.CB..\n.DCCCE\n.DCEEE\nDDD..E\n";
if (n == 6  && m == 7) cout << "6\nA.BBB.C\nAAABCCC\nA.DBE.C\nDDDFEEE\n..DFE..\n..FFF..\n";
if (n == 6  && m == 8) cout << "7\nA.BBB.C.\nAAABCCC.\nA.DBE.C.\nDDDFEEEG\n..DFEGGG\n..FFF..G\n";
if (n == 6  && m == 9) cout << "8\nA.BBBC..D\nAAAB.CDDD\nA.EBCCCFD\nEEEGHHHF.\n..EG.HFFF\n..GGGH...\n";
if (n == 7  && m == 1) cout << "0\n.\n.\n.\n.\n.\n.\n.\n";
if (n == 7  && m == 2) cout << "0\n..\n..\n..\n..\n..\n..\n..\n";
if (n == 7  && m == 3) cout << "3\nA..\nAAA\nA.B\nBBB\nC.B\nCCC\nC..\n";
if (n == 7  && m == 4) cout << "4\nA...\nAAAB\nABBB\nC..B\nCCCD\nCDDD\n...D\n";
if (n == 7  && m == 5) cout << "5\nA.BBB\nAAAB.\nA.CB.\nCCCD.\n.ECD.\n.EDDD\nEEE..\n";
if (n == 7  && m == 6) cout << "6\nA.BBB.\nAAABC.\nA.DBC.\nDDDCCC\nE.DF..\nEEEF..\nE.FFF.\n";
if (n == 7  && m == 7) cout << "8\nA.BBB.C\nAAABCCC\nA.DB.EC\nDDDEEE.\nF.DG.EH\nFFFGHHH\nF.GGG.H\n";
if (n == 7  && m == 8) cout << "9\nA.BBB..C\nAAABDCCC\nA.EBDDDC\nEEEFDGGG\n.HEF.IG.\n.HFFFIG.\nHHH.III.\n";
if (n == 7  && m == 9) cout << "10\nA.BBBC..D\nAAAB.CDDD\nA.EBCCCFD\nEEEG.FFF.\n.HEGIIIFJ\n.HGGGIJJJ\nHHH..I..J\n";
if (n == 8  && m == 1) cout << "0\n.\n.\n.\n.\n.\n.\n.\n.\n";
if (n == 8  && m == 2) cout << "0\n..\n..\n..\n..\n..\n..\n..\n..\n";
if (n == 8  && m == 3) cout << "3\nA..\nAAA\nA.B\nBBB\nC.B\nCCC\nC..\n...\n";
if (n == 8  && m == 4) cout << "4\nA...\nAAAB\nABBB\nC..B\nCCCD\nCDDD\n...D\n....\n";
if (n == 8  && m == 5) cout << "6\nA.BBB\nAAAB.\nAC.BD\n.CDDD\nCCCED\nFEEE.\nFFFE.\nF....\n";
if (n == 8  && m == 6) cout << "7\nA.BBB.\nAAABC.\nA.DBC.\nDDDCCC\nE.DFFF\nEEEGF.\nEGGGF.\n...G..\n";
if (n == 8  && m == 7) cout << "9\nA..BCCC\nAAAB.C.\nADBBBCE\n.DDDEEE\nFD.GGGE\nFFFHGI.\nFHHHGI.\n...HIII\n";
if (n == 8  && m == 8) cout << "10\nA.BBB.C.\nAAABCCC.\nAD.BEFC.\n.DEEEFFF\nDDDGEF.H\nIGGGJHHH\nIIIGJ..H\nI..JJJ..\n";
if (n == 8  && m == 9) cout << "12\nA.BBBC...\nAAABDCCCE\nA.FBDCEEE\nFFFDDDG.E\nH.FIIIGGG\nHHHJIKG.L\nHJJJIKLLL\n...JKKK.L\n";
if (n == 9  && m == 1) cout << "0\n.\n.\n.\n.\n.\n.\n.\n.\n.\n";
if (n == 9  && m == 2) cout << "0\n..\n..\n..\n..\n..\n..\n..\n..\n..\n";
if (n == 9  && m == 3) cout << "4\nA..\nAAA\nA.B\nBBB\nC.B\nCCC\nC.D\nDDD\n..D\n";
if (n == 9  && m == 4) cout << "5\nA...\nAAAB\nABBB\nC..B\nCCCD\nCDDD\nE..D\nEEE.\nE...\n";
if (n == 9  && m == 5) cout << "7\nA.BBB\nAAAB.\nAC.BD\n.CDDD\nCCCED\nFEEE.\nFFFEG\nF.GGG\n....G\n";
if (n == 9  && m == 6) cout << "8\nA.BBB.\nAAABC.\nA.DBC.\nDDDCCC\nE.DF..\nEEEF..\nEGFFFH\n.G.HHH\nGGG..H\n";
if (n == 9  && m == 7) cout << "10\nA.BBB.C\nAAABCCC\nA.DB.EC\nDDDEEE.\nF.DG.EH\nFFFGHHH\nFIGGGJH\n.I.JJJ.\nIII..J.\n";
if (n == 9  && m == 8) cout << "12\nA.BBB..C\nAAABDCCC\nAE.BDDDC\n.EEED..F\nGEHHHFFF\nGGGHIIIF\nGJ.HKIL.\n.JKKKIL.\nJJJ.KLLL\n";
if (n == 9  && m == 9) cout << "13\nA.BBB.C..\nAAABCCCD.\nA.EB.FCD.\nEEEFFFDDD\nG.E.HFIII\nGGGJHHHI.\nGK.JHL.IM\n.KJJJLMMM\nKKK.LLL.M\n";
    return 0;
}