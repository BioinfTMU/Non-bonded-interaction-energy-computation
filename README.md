# Non-bonded-interaction-energy-computation
CPU and parallelized GPU implementation

</br>
<p align="justify">
The folding of proteins is one of the biggest problems in every field of science related to
Biochemistry. Before entering water solutes, proteins do not have a three-dimensional
structure. After entering water solutes due to emerging forces between the solute and the
protein as well as interactions inside the protein gives the linear protein a three-dimensional
structure which is very important and fundamental to their functions inside a living organism.
Non-bonded interactions are one of the most influential factors to protein folding. Which
comprise of three major interaction: Vander Waals interactions, electrostatic interactions and
hydrogen bonds. Our goal in this project is to compute all of the interactions of these kinds
inside a PDB file and parallelize these computations using GPU programming. For this
purpose, we use a parallel computing platform called CUDA. We use python <a href="http://numba.pydata.org/">Numba
package</a> to parallelize computations. In the end, we compare the computation time of the
CPU program and GPU program. This comparison shows that increasing number of
computation, CPU time exponentially increases and GPU time linearly increases and GPU
Time is lower than CPU time.
</p>
