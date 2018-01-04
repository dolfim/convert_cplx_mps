# Convert complex MPS checkpoints

## Configure

1. Install ALPS with Install MPS framework activated: ```ALPS_INSTALL_MPS_FRAMEWORK=ON```

1. Configure with all options:
```bash
cmake -DALPS_DIR=$HOME/opt/alps-trunk/share/alps -DALPS_MPS_DIR=$HOME/opt/alps-trunk/share/alps ..
```

## License

This code is licensed under the ALPS Applications License.
Usage of the ALPS library requires to be acknowledge the following citations:
* B. Bauer et al., J. Stat. Mech. (2011) P05001. doi: [10.1088/1742-5468/2011/05/P05001](http://dx.doi.org/10.1088/1742-5468/2011/05/P05001)
* M. Dolfi et al., Computer Physics Communications 185, 3430 (2014). doi: [10.1016/j.cpc.2014.08.019](http://dx.doi.org/10.1016/j.cpc.2014.08.019)
