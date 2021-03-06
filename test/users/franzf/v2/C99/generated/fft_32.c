/***************************************************************
This code was generated by  Spiral 5.0 beta, www.spiral.net --
Copyright (c) 2005, Carnegie Mellon University
All rights reserved.
The code is distributed under a BSD style license
(see http://www.opensource.org/licenses/bsd-license.php)

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

* Redistributions of source code must retain the above copyright
  notice, reference to Spiral, this list of conditions and the
  following disclaimer.
* Redistributions in binary form must reproduce the above
  copyright notice, this list of conditions and the following
  disclaimer in the documentation and/or other materials provided
  with the distribution.
* Neither the name of Carnegie Mellon University nor the name of its
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*AS IS* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
******************************************************************/

/*	CPU: Intel Core2Duo at 2660 MHz, 2 cores, SSE3
	OS: Microsoft WindowsXP 32-bit
	SVN: 5591 (modified)
	language: c.icl.opt
	timestamp: Dec 6, 2007; 13:43:49
	transform: DFT(32, 1)
	source file: "fft_32.c(.c)"
	performance: 665 cycles, 3200 Mflop/s

algorithm: DFT_GT_CT( DFT(32, 1),
  GT_NthLoop( GT(DFT(4, 1), XChain([ 0, 1 ]), XChain([ 0, 1 ]), [ 8 ]),
    GT_Base( GT(DFT(4, 1), XChain([ 0 ]), XChain([ 0 ]), [  ]),
      DFT_GT_CT( DFT(4, 1),
        GT_NthLoop( GT(DFT(2, 1), XChain([ 0, 1 ]), XChain([ 0, 1 ]), [ 2 ]),
          GT_Base( GT(DFT(2, 1), XChain([ 0 ]), XChain([ 0 ]), [  ]),
            DFT_Base( DFT(2, 1) ) ),
          Info_Base( InfoNt(1) ) ),
        GT_NthLoop( GT(DFT(2, 1), XChain([ 0, 1 ]), XChain([ 1, 0 ]), [ 2 ]),
          GT_Base( GT(DFT(2, 1), XChain([ 0 ]), XChain([ 0 ]), [  ]),
            DFT_Base( DFT(2, 1) ) ),
          Info_Base( InfoNt(1) ) ) ) ),
    Info_Base( InfoNt(1) ) ),
  GT_NthLoop( GT(DFT(8, 1), XChain([ 0, 1 ]), XChain([ 1, 0 ]), [ 4 ]),
    GT_Base( GT(DFT(8, 1), XChain([ 0 ]), XChain([ 0 ]), [  ]),
      DFT_GT_CT( DFT(8, 1),
        GT_NthLoop( GT(DFT(2, 1), XChain([ 0, 1 ]), XChain([ 0, 1 ]), [ 4 ]),
          GT_Base( GT(DFT(2, 1), XChain([ 0 ]), XChain([ 0 ]), [  ]),
            DFT_Base( DFT(2, 1) ) ),
          Info_Base( InfoNt(1) ) ),
        GT_NthLoop( GT(DFT(4, 1), XChain([ 0, 1 ]), XChain([ 1, 0 ]), [ 2 ]),
          GT_Base( GT(DFT(4, 1), XChain([ 0 ]), XChain([ 0 ]), [  ]),
            DFT_GT_CT( DFT(4, 1),
              GT_NthLoop( GT(DFT(2, 1), XChain([ 0, 1 ]), XChain([ 0, 1 ]), [ 2 ]),
                GT_Base( GT(DFT(2, 1), XChain([ 0 ]), XChain([ 0 ]), [  ]),
                  DFT_Base( DFT(2, 1) ) ),
                Info_Base( InfoNt(1) ) ),
              GT_NthLoop( GT(DFT(2, 1), XChain([ 0, 1 ]), XChain([ 1, 0 ]), [ 2 ]),
                GT_Base( GT(DFT(2, 1), XChain([ 0 ]), XChain([ 0 ]), [  ]),
                  DFT_Base( DFT(2, 1) ) ),
                Info_Base( InfoNt(1) ) ) ) ),
          Info_Base( InfoNt(1) ) ) ) ),
    Info_Base( InfoNt(1) ) ) )
*/

#include <include/omega64c.h>

void init_fft32() {
}

void fft32(_Complex double  *Y, _Complex double  *X) {
    _Complex double s168, s169, s170, s171, s172, s173, s174, 
        s175, s176, s177, s178, s179, s180, s181, s182, 
        s183, s184, s185, s186, s187, s188, s189, s190, 
        s191, s192, s193, s194, s195, s196, s197, s198, 
        s199, s200, s201, s202, s203, s204, s205, s206, 
        s207, s208, s209, s210, s211, s212, s213, s214, 
        s215, s216, t593, t594, t595, t596, t597, t598, 
        t599, t600, t601, t602, t603, t604, t605, t606, 
        t607, t608, t609, t610, t611, t612, t613, t614, 
        t615, t616, t617, t618, t619, t620, t621, t622, 
        t623, t624, t625, t626, t627, t628, t629, t630, 
        t631, t632, t633, t634, t635, t636, t637, t638, 
        t639, t640, t641, t642, t643, t644, t645, t646, 
        t647, t648, t649, t650, t651, t652, t653, t654, 
        t655, t656, t657, t658, t659, t660, t661, t662, 
        t663, t664, t665, t666, t667, t668, t669, t670, 
        t671;
    t593 = (X[0] + X[16]);
    t594 = (X[0] - X[16]);
    t595 = (X[8] + X[24]);
    t596 = (t593 + t595);
    t597 = (t593 - t595);
    s168 = (__I__*(X[8] - X[24]));
    t598 = (t594 + s168);
    t599 = (t594 - s168);
    t600 = (X[4] + X[20]);
    t601 = (X[4] - X[20]);
    t602 = (X[12] + X[28]);
    t603 = (t600 + t602);
    s169 = (__I__*(X[12] - X[28]));
    t604 = (t596 + t603);
    t605 = (t596 - t603);
    s170 = ((0.70710678118654757 + __I__ * 0.70710678118654757)*(t601 + s169));
    t606 = (t598 + s170);
    t607 = (t598 - s170);
    s171 = (__I__*(t600 - t602));
    t608 = (t597 + s171);
    t609 = (t597 - s171);
    s172 = ((-0.70710678118654757 + __I__ * 0.70710678118654757)*(t601 - s169));
    t610 = (t599 + s172);
    t611 = (t599 - s172);
    t612 = (X[1] + X[17]);
    t613 = (X[1] - X[17]);
    t614 = (X[9] + X[25]);
    t615 = (t612 + t614);
    t616 = (t612 - t614);
    s173 = (__I__*(X[9] - X[25]));
    t617 = (t613 + s173);
    t618 = (t613 - s173);
    t619 = (X[5] + X[21]);
    t620 = (X[5] - X[21]);
    t621 = (X[13] + X[29]);
    t622 = (t619 + t621);
    s174 = (__I__*(X[13] - X[29]));
    t623 = (t615 + t622);
    s175 = ((0.70710678118654757 + __I__ * 0.70710678118654757)*(t620 + s174));
    s176 = (__I__*(t619 - t621));
    s177 = ((-0.70710678118654757 + __I__ * 0.70710678118654757)*(t620 - s174));
    t624 = (X[2] + X[18]);
    t625 = (X[2] - X[18]);
    t626 = (X[10] + X[26]);
    t627 = (t624 + t626);
    t628 = (t624 - t626);
    s178 = (__I__*(X[10] - X[26]));
    t629 = (t625 + s178);
    t630 = (t625 - s178);
    t631 = (X[6] + X[22]);
    t632 = (X[6] - X[22]);
    t633 = (X[14] + X[30]);
    t634 = (t631 + t633);
    s179 = (__I__*(X[14] - X[30]));
    t635 = (t627 + t634);
    s180 = ((0.70710678118654757 + __I__ * 0.70710678118654757)*(t632 + s179));
    s181 = (__I__*(t631 - t633));
    s182 = ((-0.70710678118654757 + __I__ * 0.70710678118654757)*(t632 - s179));
    t636 = (X[3] + X[19]);
    t637 = (X[3] - X[19]);
    t638 = (X[11] + X[27]);
    t639 = (t636 + t638);
    t640 = (t636 - t638);
    s183 = (__I__*(X[11] - X[27]));
    t641 = (t637 + s183);
    t642 = (t637 - s183);
    t643 = (X[7] + X[23]);
    t644 = (X[7] - X[23]);
    t645 = (X[15] + X[31]);
    t646 = (t643 + t645);
    s184 = (__I__*(X[15] - X[31]));
    t647 = (t639 + t646);
    s185 = ((0.70710678118654757 + __I__ * 0.70710678118654757)*(t644 + s184));
    s186 = (__I__*(t643 - t645));
    s187 = ((-0.70710678118654757 + __I__ * 0.70710678118654757)*(t644 - s184));
    t648 = (t604 + t635);
    t649 = (t604 - t635);
    t650 = (t623 + t647);
    Y[0] = (t648 + t650);
    Y[16] = (t648 - t650);
    s188 = (__I__*(t623 - t647));
    Y[8] = (t649 + s188);
    Y[24] = (t649 - s188);
    s189 = ((0.92387953251128674 + __I__ * 0.38268343236508978)*(t629 + s180));
    t651 = (t606 + s189);
    t652 = (t606 - s189);
    s190 = ((0.98078528040323043 + __I__ * 0.19509032201612825)*(t617 + s175));
    s191 = ((0.83146961230254524 + __I__ * 0.55557023301960218)*(t641 + s185));
    t653 = (s190 + s191);
    Y[1] = (t651 + t653);
    Y[17] = (t651 - t653);
    s192 = (__I__*(s190 - s191));
    Y[9] = (t652 + s192);
    Y[25] = (t652 - s192);
    s193 = ((0.70710678118654757 + __I__ * 0.70710678118654757)*(t628 + s181));
    t654 = (t608 + s193);
    t655 = (t608 - s193);
    s194 = ((0.92387953251128674 + __I__ * 0.38268343236508978)*(t616 + s176));
    s195 = ((0.38268343236508978 + __I__ * 0.92387953251128674)*(t640 + s186));
    t656 = (s194 + s195);
    Y[2] = (t654 + t656);
    Y[18] = (t654 - t656);
    s196 = (__I__*(s194 - s195));
    Y[10] = (t655 + s196);
    Y[26] = (t655 - s196);
    s197 = ((0.38268343236508978 + __I__ * 0.92387953251128674)*(t630 + s182));
    t657 = (t610 + s197);
    t658 = (t610 - s197);
    s198 = ((0.83146961230254524 + __I__ * 0.55557023301960218)*(t618 + s177));
    s199 = ((-0.19509032201612825 + __I__ * 0.98078528040323043)*(t642 + s187));
    t659 = (s198 + s199);
    Y[3] = (t657 + t659);
    Y[19] = (t657 - t659);
    s200 = (__I__*(s198 - s199));
    Y[11] = (t658 + s200);
    Y[27] = (t658 - s200);
    s201 = (__I__*(t627 - t634));
    t660 = (t605 + s201);
    t661 = (t605 - s201);
    s202 = ((0.70710678118654757 + __I__ * 0.70710678118654757)*(t615 - t622));
    s203 = ((-0.70710678118654757 + __I__ * 0.70710678118654757)*(t639 - t646));
    t662 = (s202 + s203);
    Y[4] = (t660 + t662);
    Y[20] = (t660 - t662);
    s204 = (__I__*(s202 - s203));
    Y[12] = (t661 + s204);
    Y[28] = (t661 - s204);
    s205 = ((-0.38268343236508978 + __I__ * 0.92387953251128674)*(t629 - s180));
    t663 = (t607 + s205);
    t664 = (t607 - s205);
    s206 = ((0.55557023301960218 + __I__ * 0.83146961230254524)*(t617 - s175));
    s207 = ((-0.98078528040323043 + __I__ * 0.19509032201612825)*(t641 - s185));
    t665 = (s206 + s207);
    Y[5] = (t663 + t665);
    Y[21] = (t663 - t665);
    s208 = (__I__*(s206 - s207));
    Y[13] = (t664 + s208);
    Y[29] = (t664 - s208);
    s209 = ((-0.70710678118654757 + __I__ * 0.70710678118654757)*(t628 - s181));
    t666 = (t609 + s209);
    t667 = (t609 - s209);
    s210 = ((0.38268343236508978 + __I__ * 0.92387953251128674)*(t616 - s176));
    s211 = ((-0.92387953251128674 - __I__ * 0.38268343236508978)*(t640 - s186));
    t668 = (s210 + s211);
    Y[6] = (t666 + t668);
    Y[22] = (t666 - t668);
    s212 = (__I__*(s210 - s211));
    Y[14] = (t667 + s212);
    Y[30] = (t667 - s212);
    s213 = ((-0.92387953251128674 + __I__ * 0.38268343236508978)*(t630 - s182));
    t669 = (t611 + s213);
    t670 = (t611 - s213);
    s214 = ((0.19509032201612825 + __I__ * 0.98078528040323043)*(t618 - s177));
    s215 = ((-0.55557023301960218 - __I__ * 0.83146961230254524)*(t642 - s187));
    t671 = (s214 + s215);
    Y[7] = (t669 + t671);
    Y[23] = (t669 - t671);
    s216 = (__I__*(s214 - s215));
    Y[15] = (t670 + s216);
    Y[31] = (t670 - s216);
}
