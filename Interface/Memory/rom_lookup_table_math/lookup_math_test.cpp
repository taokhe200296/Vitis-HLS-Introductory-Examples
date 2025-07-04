/*
 * Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
 * Copyright 2022-2025 Advanced Micro Devices, Inc. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <stdlib.h>
#include "lookup_math.h"

int main() {
    din1_t data1_i = 1;
    din2_t data2_i = 100;
    dout_t data_o;

    int i, retval = 0;
    ofstream FILE;

    // Save the results to a file
    FILE.open("result.dat");

    // Call the function for multiple transactions
    for (i = 0; i < 64; i++) {
        data_o = lookup_math(data1_i, data2_i);
        FILE << data_o << endl;
        data1_i = data1_i + 1;
        data2_i = data2_i + 1;
    }
    FILE.close();

    // Compare the results file with the golden results
    retval = system("diff --brief -w result.dat result.golden.dat");
    if (retval != 0) {
        cout << "Test failed  !!!" << endl;
        retval = 1;
    } else {
        cout << "Test passed !" << endl;
    }

    // Return 0 if the test passes
    return retval;
}
