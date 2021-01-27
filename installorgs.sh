mkdir ./temp
mkdir ./orgs
cd ./temp
curl https://www.cavestory.org/music/all.zip --output all.zip
unzip ./all -d ../orgs
cd ../
rm -d -r ./temp
