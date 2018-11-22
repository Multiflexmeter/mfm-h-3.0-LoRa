pipeline {
  agent any
  stages {
      stage('Update remote source') {
        steps {
          sshagent(credentials: ['test-server-ssh-key']) {
              configFileProvider([configFile(fileId: 'test-server-ip', variable: 'TEST_SERVER_IP')]) {
                sh 'ssh `cat $TEST_SERVER_IP` -o StrictHostKeyChecking=no \'git clone -b dev https://github.com/Multiflexmeter/mfm-h-3.0-LoRa\''
            }
          }
        }
      }
    stage('Test native') {
      steps {
        sshagent(credentials: ['test-server-ssh-key']) {
            configFileProvider([configFile(fileId: 'test-server-ip', variable: 'TEST_SERVER_IP')]) {
              sh 'ssh `cat $TEST_SERVER_IP` -o StrictHostKeyChecking=no \'cd mfm-h-3.0-LoRa && pio lib install lib/*/ && pio test -e native\''
          }
        }
      }
    }
    stage('Test UNO') {
      steps {
        sshagent(credentials: ['test-server-ssh-key']) {
            configFileProvider([configFile(fileId: 'test-server-ip', variable: 'TEST_SERVER_IP')]) {
              sh 'ssh `cat $TEST_SERVER_IP` -o StrictHostKeyChecking=no \'cd mfm-h-3.0-LoRa && pio lib install lib/*/ && pio test -e uno\''
          }
        }
      }
    }
  }
}
