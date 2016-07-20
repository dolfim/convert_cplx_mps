/*****************************************************************************
 *
 * ALPS MPS DMRG Project
 *
 * Copyright (C) 2014 Institute for Theoretical Physics, ETH Zurich
 *               2013-2013 by Michele Dolfi <dolfim@phys.ethz.ch>
 *
 * This software is part of the ALPS Applications, published under the ALPS
 * Application License; you can use, redistribute it and/or modify it under
 * the terms of the license, either version 1 or (at your option) any later
 * version.
 *
 * You should have received a copy of the ALPS Application License along with
 * the ALPS Applications; see the file LICENSE.txt. If not, the license is also
 * available from http://alps.comp-phys.org/.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 *****************************************************************************/
#include <cmath>
#include <iterator>
#include <iostream>
#include <fstream>
#include <sys/time.h>
#include <sys/stat.h>

using std::cerr;
using std::cout;
using std::endl;

#include "dmrg/block_matrix/detail/alps.hpp"
typedef alps::numeric::matrix<double> matrix;
typedef alps::numeric::matrix<std::complex<double> > cmatrix;

#include "dmrg/mp_tensors/mps.h"

typedef NU1 symm;

#include "dmrg/utils/DmrgParameters.h"


int main(int argc, char ** argv)
{
    if (argc != 3) {
        std::cout << "Usage: " << argv[0] << " <complex.chkp> <real.chkp>" << std::endl;
        return 1;
    }
    
    MPS<cmatrix, symm> mps_in;
    load(argv[1], mps_in);
    
    MPS<matrix, symm> mps_out(mps_in.length());
    for (int i=0; i<mps_in.length(); ++i) {
        mps_in[i].make_left_paired();
        block_matrix<matrix, symm> m;
        for (int k=0; k<mps_in[i].data().n_blocks(); ++k)
            m.insert_block(maquis::bindings::matrix_cast<matrix>(mps_in[i].data()[k]), mps_in[i].data().left_basis()[k].first, mps_in[i].data().right_basis()[k].first);
        mps_out[i] = MPSTensor<matrix, symm>(mps_in[i].site_dim(),mps_in[i].row_dim(), mps_in[i].col_dim(), m, LeftPaired);
    }
    
    save(argv[1], mps_out);
}
