# X-Ray Classification [Pneumonia/Normal]

- Dataset Link: https://www.kaggle.com/datasets/pcbreviglieri/pneumonia-xray-images

- You can use Jupyter Notebook, but it will be easier in Google Colab or Kaggle Notebook.

- How to use it in colab:

  - First, we will extract the dataset directly from Kaggle using the Kaggle API. To do this, we need to create an API token that is located in the Account section under the Kaggle API tab. Click on ‘Create a new API token’ and a json file will be downloaded.

  - Run the following lines of codes to instal the needed libraries and upload the json file.

  ```
  ! pip install -q kaggle
  from google.colab import files
  files.upload()
  ! mkdir ~/.kaggle
  ! cp kaggle.json ~/.kaggle/
  ! chmod 600 ~/.kaggle/kaggle.json
  ```

  - When prompted to ‘Choose Files,’ upload the downloaded json file. Running the next line of code is going to download the dataset. To get the dataset API command to download the dataset, click the 3 dots in the data section of the Kaggle dataset page and click the ‘Copy API command’ button and paste it with the `!`

  ```
  ! kaggle datasets download -d pcbreviglieri/pneumonia-xray-images
  ```
