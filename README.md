# Agency EMS SpeedUp Experiment System

This code allows you to run simple reaction time experiments in which your participants' reaction time is accelerated by means of Electrical Muscle Stimulation (EMS). 

This code was derived from 'Preserving Agency During Electrical Muscle Stimulation Training Speeds up Reaction Time Directly After Removing EMS', [[https://lab.plopes.org/#EMSspeedup|(more info & read our CHI 2021 Paper]], by Shunichi Kasahara, Kazuma Takada, Jun Nishida, Kazuhisa Shibata, Shinsuke Shimojo and Pedro Lopes. 

### Software pre-requisites

This uses TouchDesigner. We recommend using the "64Bit Build 2018.28120" version. Due to some backward-incompatibility in TouchDesigner, the ``pulse function`` might not work as expected in the newer versions. 

### Hardware pre-requisites

* We used a BioSync Electrical Muscle Stimulator (design by [[https://junis.sakura.ne.jp/wp/portfolio-item/biosync/|Jun Nishida, CHI2017 Paper]]), via Serial (over USB); please refer to [[https://lab.plopes.org/#EMSspeedup(our CHI 2021 Paper]] for hardware requirements.
* We used an Arduino microcontroller connected to a simple capacitive touch sensor as our button for the reaction time tests (code included); please refer to [[https://lab.plopes.org/#EMSspeedup(our CHI 2021 Paper]] for hardware requirements.

# Software Code overview (in TouchDesigner)

- AgencyGateLearn_PreStudy.toe
Run this code to acquire data for "Agency Curve" (refer to Study #1 in [[https://lab.plopes.org/#EMSspeedup(our CHI 2021 Paper]])

- AgencyGateLearn_MainStudy.toe
Run this code to acquire  data for the Main Study (refer to Study #2 in [[https://lab.plopes.org/#EMSspeedup(our CHI 2021 Paper]]

# Middleware Code overview (in Arduino)

- ReactionTimeMeasure
This is a simple firmware that talks between an Arduino and the TouchDesigner experiments, it implements a simple serial protocol that was designed for this study. 
