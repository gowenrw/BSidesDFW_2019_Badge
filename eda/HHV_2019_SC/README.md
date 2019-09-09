# BSidesDFW_2019_Badge / Electronic Design Automation / Hardware Hacking Village 2019 Soldering Challenge

This is where all the KiCad 5.x files related to the BSidesDFW Hardware Hacking Village 2019 Soldering Challenge board


## File Structure

This is the file structure of this repository

* [/](/README.md) - Home
* [/eda](/eda/) - Electronic Design Automation files for the badge PCB (EDA is KiCad)
  * [/eda/HHV_2019_SC/](/eda/HHV_2019_SC/) - YOU ARE HERE
    * ./<filename>.pro - project file. Holds parameters that apply to the entire project (schematic and PCB layout).
    * ./<filename>.sch - schematic file.
    * ./<filename>.kicad_pcb - the new PCB layout file.
    * ./<filename>.net - netlist in "Pcbnew" format
    * ./<filename>.bak - backup of schematic file.
    * ./<filename>.kicad_pcb-bak - backup of the new PCB layout file.
    * ./<filename>-cache.lib - a local cache copy of all the symbols used in the schematic
    * ./fp-lib-table - Footprint library list
    * ./sym-lib-table - Schematic library list
    * [./3d_models/](/eda/HHV_2019_SC/3d_models/) - This directory contains footprint 3d model files
    * [./gerber/](/eda/HHV_2019_SC/gerber/) - This directory contains gerber formatted files for manufacturing
    * [./lib_fp/](/eda/HHV_2019_SC/lib_fp/) - This directory contains footprint module directories
    * [./lib_sh/](/eda/HHV_2019_SC/lib_sh/) - This directory contains schematic library files
    * [./pdf/](/eda/HHV_2019_SC/pdf/) - This directory contains pdf prints of schematics and cad files
