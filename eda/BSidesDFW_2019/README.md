# BSidesDFW_2019_Badge / Electronic Design Automation / Main Badge

This is where all the KiCad 5.x files related to the main badge

## File Structure

This is the file structure of this repository

* [/](/) - Home
* [/eda](/eda/) - Electronic Design Automation files for the badge PCB (EDA is KiCad)
  * [/eda/BSidesDFW_2019/](/eda/BSidesDFW_2019/) - YOU ARE HERE
    * ./<filename>.pro - project file. Holds parameters that apply to the entire project (schematic and PCB layout).
    * ./<filename>.sch - schematic file.
    * ./<filename>.kicad_pcb - the new PCB layout file.
    * ./<filename>.net - netlist in "Pcbnew" format
    * ./<filename>.bak - backup of schematic file.
    * ./<filename>.kicad_pcb-bak - backup of the new PCB layout file.
    * ./<filename>-cache.lib - a local cache copy of all the symbols used in the schematic
    * ./fp-lib-table - Footprint library list
    * ./sym-lib-table - Schematic library list
    * [./3d_models/](./3d_models/) - This directory contains footprint 3d model files
    * [./gerber/](./gerber/) - This directory contains gerber formatted files for manufacturing
    * [./lib_fp/](./lib_fp/) - This directory contains footprint module directories
    * [./lib_sh/](./lib_sh/) - This directory contains schematic library files
