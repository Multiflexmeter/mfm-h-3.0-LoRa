pipeline {
  agent any
  stages {
    stage('Test native') {
      steps {
        sh 'pio test -e native'
      }
    }
    stage('Test UNO') {
      steps {
        withCredentials([string(credentialsId: 'PIO_AUTH', variable: 'PIO_AUTH')]) {
          sh 'set -x'
          sh 'export PLATFORMIO_AUTH_TOKEN=$PIO_AUTH'
          sh 'pio remote --agent multiflexmeter-desktop test -e uno'
        }
      }
    }
  }
}
