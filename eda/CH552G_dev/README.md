# BSidesDFW_2019_Badge / Electronic Design Automation / Prototypes / CH552 Prototype

This is where all the KiCad 5.x files related to the CH552 prototype PCB

Note that this prototype is specific to the CH552G chip which is SOP-16 and will not work on the CH552T chip which is TSSOP-20.

## File Structure

This is the file structure of this repository

* [/](/README.md) - Home
* [/eda](/eda/) - Electronic Design Automation files for the badge PCB (EDA is KiCad)
  * [/eda/CH552G_dev/](/eda/CH552G_dev/) - YOU ARE HERE
    * ./<filename>.pro - project file. Holds parameters that apply to the entire project (schematic and PCB layout).
    * ./<filename>.sch - schematic file.
    * ./<filename>.kicad_pcb - the new PCB layout file.
    * ./<filename>.net - netlist in "Pcbnew" format
    * ./<filename>.bak - backup of schematic file.
    * ./<filename>.kicad_pcb-bak - backup of the new PCB layout file.
    * ./<filename>-cache.lib - a local cache copy of all the symbols used in the schematic
    * ./fp-lib-table - Footprint library list
    * ./sym-lib-table - Schematic library list
    * [./3d_models/](/eda/CH552G_dev/3d_models/) - This directory contains footprint 3d model files
    * [./gerber/](/eda/CH552G_dev/gerber/) - This directory contains gerber formatted files for manufacturing
    * [./lib_fp/](/eda/CH552G_dev/lib_fp/) - This directory contains footprint module directories
    * [./lib_sh/](/eda/CH552G_dev/lib_sh/) - This directory contains schematic library files
