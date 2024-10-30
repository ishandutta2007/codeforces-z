namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Extensions.Diagnostics;

    operation Set(q : Qubit, val : Result) : () {
        body {
            let res = M(q);
            if (res != val) {
                X(q);
            }
        }
    }

    operation Solve(qs : Qubit[]) : Int {
        body {
            H(qs[0]);
            CNOT(qs[0], qs[1]);
            H(qs[0]);

            X(qs[0]);
            X(qs[1]);

            mutable res = 0;

            if (M(qs[0]) == One) {
                set res = res + 2;
            }
            if (M(qs[1]) == One) {
                set res = res + 1;
            }

            return res;
        }
    }

    operation Go() : (Int) {
        body {
            let count = 2;
            using (qs = Qubit[count]) {
                ResetAll(qs);

                X(qs[0]);
                X(qs[1]);
                H(qs[0]);
                CNOT(qs[0], qs[1]);
                H(qs[1]);

                //X(qs[0]);
                //X(qs[1]);

                DumpMachine("dump.txt");
                let res = Solve(qs);
                Message($"res: {res}");

                ResetAll(qs);
            }
            return 0;
        }
    }
}