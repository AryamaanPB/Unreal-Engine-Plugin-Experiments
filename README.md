# PBExp Plugin
## _A collection of random experiments_

This plugin is a collection of basic components and scenes that I get to play around with and you get to use if it fits your needs.

## Features
#### PBScaleComponents
- ##### UPBScaleComponent
    - ##### Properties
        - **SelectedAlgo**
            - *Type* : **EPBAlgorithm**
            - *Description*: The Algorithm you choose to scale your components
            - *Options*:
                - **Sine**: Follows a Sine wave: sin(x)
                - **Cosine**: Follows a Cosine wave: cos(x)
        - **MaxScaleFactor**
            - *Type*: **float**
            - *Description*: The maximum multiplier to your actor's scale
        - **MinScaleFactor**
            - *Type*: **float**
            - *Description*: The minimum multiplier to your actor's scale
        - **Frequency**
            - *Type*: **float**
            - *Description*: The frequency with which the scale should modulate
        - **bStrictlyPositive**
            - *Type*: **bool**
            - *Description*: Whether the Sine wave should go below 0.0 Changes MinScaleFactor to |MinScaleFactor|
    - ##### Demo
        - PBScaleComponent Setup
            - ![PBScaleComponent Setup](https://github.com/AryamaanPB/Unreal-Engine-Plugin-Experiments/blob/pbscalecomponents/Plugins/PBExp/Resources/PBScaleComponent%20Setup.gif))
        - PBScaleComponent Sine Scaling
            -  ![PBScaleComponent Sine Scaling](https://github.com/AryamaanPB/Unreal-Engine-Plugin-Experiments/blob/pbscalecomponents/Plugins/PBExp/Resources/PBScaleComponent%20Sine.gif))
        -  PBScaleComponent Cosine Scaling
            -  ![PBScaleComponent Cosine Scaling](https://github.com/AryamaanPB/Unreal-Engine-Plugin-Experiments/blob/pbscalecomponents/Plugins/PBExp/Resources/PBScaleComponent%20Cosine.gif))
        -  PBScaleComponent Demo
            -  [PBScaleComponent Demo](https://github.com/AryamaanPB/Unreal-Engine-Plugin-Experiments/blob/pbscalecomponents/Plugins/PBExp/Resources/PBScaleComponent%20Demo.gif))
