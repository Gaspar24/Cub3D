## Setup

1. Extract the MiniLibX library:
    ```sh
    tar -xvzf 'minilibx-linux(1).tgz'
    ```

2. 
   ```sh 
    make 
    ```
4. 
    ```sh 
    ./cub3d map/"map_name"  
    ```


![raycasting](https://github.com/user-attachments/assets/ac254074-9ceb-4748-8fae-2fef260b060d)

***IMPORTANT***
changed get_next_line to reset after it's used inside a fucntion, in order to delete the Buffer stored;